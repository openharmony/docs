# native_avcapability.h

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yang-xiaoyu5-->
<!--Designer: @dpy2650-->
<!--Tester: @cyakee-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=e8c5c20c2e613f3213142be6ac06f0d49df96fa7 translatedAt=2026-08-01T07:20:25.165Z pushedAt=2026-08-01T08:00:26.632Z -->

## Overview

The file declares the native APIs used to query the codec capability.

**File to include**: <multimedia/player_framework/native_avcapability.h>

**Library**: libnative_media_codecbase.so

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Related module**: [AVCapability](capi-avcapability.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AVRange](capi-avcapability-oh-avrange.md) | OH_AVRange | Describes the value range, which contains the minimum value and maximum value.|
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) | OH_AVCapability | Describes a native object for the OH_AVCapability interface.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AVCodecCategory](#oh_avcodeccategory) | OH_AVCodecCategory | Enumerates the codec categories.|
| [OH_AVCodecType](#oh_avcodectype) | OH_AVCodecType | Codec type.|
| [OH_AVCapabilityFeature](#oh_avcapabilityfeature) | OH_AVCapabilityFeature | Enumerates the optional features that can be used in specific codec scenarios.|

### Functions

| Name| Description|
| -- | -- |
| [OH_AVCapability *OH_AVCodec_GetCapability(const char *mime, bool isEncoder)](#oh_avcodec_getcapability) | Obtains the codec capability recommended by the system.|
| [OH_AVCapability *OH_AVCodec_GetCapabilityByCategory(const char *mime, bool isEncoder, OH_AVCodecCategory category)](#oh_avcodec_getcapabilitybycategory) | Obtains the codec capability by category, which can be a hardware codec or software codec.|
| [OH_AVCapability **OH_AVCodec_GetCapabilityList(OH_AVCodecType codecType, uint32_t *count)](#oh_avcodec_getcapabilitylist) | Obtains the list of capabilities for the specified codec type. This function retrieves all matching codec capabilities supported by the system based on the provided codec type.|
| [bool OH_AVCapability_IsHardware(OH_AVCapability *capability)](#oh_avcapability_ishardware) | Checks whether a codec capability instance describes a hardware codec.|
| [bool OH_AVCapability_IsSecure(OH_AVCapability *capability)](#oh_avcapability_issecure) | Checks whether the capability instance describes a DRM decoder.|
| [const char *OH_AVCapability_GetName(OH_AVCapability *capability)](#oh_avcapability_getname) | Obtains the corresponding codec name. |
| [const char *OH_AVCapability_GetMimeType(OH_AVCapability *capability)](#oh_avcapability_getmimetype) | Obtains the MIME type of the codec.|
| [bool OH_AVCapability_CheckMimeType(OH_AVCapability *capability, const char *mimeType)](#oh_avcapability_checkmimetype) | Checks whether the MIME type of the codec matches the specified MIME type.|
| [int32_t OH_AVCapability_GetMaxSupportedInstances(OH_AVCapability *capability)](#oh_avcapability_getmaxsupportedinstances) | Obtains the maximum number of codec instances supported by a codec.|
| [OH_AVErrCode OH_AVCapability_GetEncoderBitrateRange(OH_AVCapability *capability, OH_AVRange *bitrateRange)](#oh_avcapability_getencoderbitraterange) | Obtains the bit rate range supported by an encoder.|
| [bool OH_AVCapability_IsEncoderBitrateModeSupported(OH_AVCapability *capability, OH_BitrateMode bitrateMode)](#oh_avcapability_isencoderbitratemodesupported) | Checks whether an encoder supports a specific bit rate mode.|
| [OH_AVErrCode OH_AVCapability_GetEncoderQualityRange(OH_AVCapability *capability, OH_AVRange *qualityRange)](#oh_avcapability_getencoderqualityrange) | Obtains the quality range supported by an encoder.|
| [OH_AVErrCode OH_AVCapability_GetEncoderComplexityRange(OH_AVCapability *capability, OH_AVRange *complexityRange)](#oh_avcapability_getencodercomplexityrange) | Obtains the complexity range supported by an encoder.|
| [OH_AVErrCode OH_AVCapability_GetAudioSupportedSampleRates(OH_AVCapability *capability, const int32_t **sampleRates, uint32_t *sampleRateNum)](#oh_avcapability_getaudiosupportedsamplerates) | Obtains the sample rates supported by an audio codec.|
| [OH_AVErrCode OH_AVCapability_GetAudioSupportedSampleRateRanges(OH_AVCapability *capability, OH_AVRange **sampleRateRanges, uint32_t *rangesNum)](#oh_avcapability_getaudiosupportedsamplerateranges) | Obtains the sample rate ranges supported by an audio codec.|
| [OH_AVErrCode OH_AVCapability_GetAudioChannelCountRange(OH_AVCapability *capability, OH_AVRange *channelCountRange)](#oh_avcapability_getaudiochannelcountrange) | Obtains the count range of audio channels supported by an audio codec.|
| [OH_AVErrCode OH_AVCapability_GetVideoWidthAlignment(OH_AVCapability *capability, int32_t *widthAlignment)](#oh_avcapability_getvideowidthalignment) | Obtains the video width alignment supported by a video codec.|
| [OH_AVErrCode OH_AVCapability_GetVideoHeightAlignment(OH_AVCapability *capability, int32_t *heightAlignment)](#oh_avcapability_getvideoheightalignment) | Obtains the video height alignment supported by a video codec.|
| [OH_AVErrCode OH_AVCapability_GetVideoWidthRangeForHeight(OH_AVCapability *capability, int32_t height, OH_AVRange *widthRange)](#oh_avcapability_getvideowidthrangeforheight) | Obtains the video width range supported by a video codec based on a given height.|
| [OH_AVErrCode OH_AVCapability_GetVideoHeightRangeForWidth(OH_AVCapability *capability, int32_t width, OH_AVRange *heightRange)](#oh_avcapability_getvideoheightrangeforwidth) | Obtains the video height range supported by a video codec based on a given width.|
| [OH_AVErrCode OH_AVCapability_GetVideoWidthRange(OH_AVCapability *capability, OH_AVRange *widthRange)](#oh_avcapability_getvideowidthrange) | Obtains the video width range supported by a video codec.|
| [OH_AVErrCode OH_AVCapability_GetVideoHeightRange(OH_AVCapability *capability, OH_AVRange *heightRange)](#oh_avcapability_getvideoheightrange) | Obtains the video height range supported by a video codec.|
| [bool OH_AVCapability_IsVideoSizeSupported(OH_AVCapability *capability, int32_t width, int32_t height)](#oh_avcapability_isvideosizesupported) | Checks whether a video codec supports a specific video size.|
| [OH_AVErrCode OH_AVCapability_GetVideoFrameRateRange(OH_AVCapability *capability, OH_AVRange *frameRateRange)](#oh_avcapability_getvideoframeraterange) | Obtains the video frame rate range supported by a video codec.|
| [OH_AVErrCode OH_AVCapability_GetVideoFrameRateRangeForSize(OH_AVCapability *capability, int32_t width, int32_t height, OH_AVRange *frameRateRange)](#oh_avcapability_getvideoframeraterangeforsize) | Obtains the video frame rate range supported by a video codec based on a given video size.|
| [bool OH_AVCapability_AreVideoSizeAndFrameRateSupported(OH_AVCapability *capability, int32_t width, int32_t height, int32_t frameRate)](#oh_avcapability_arevideosizeandframeratesupported) | Checks whether a video codec supports the combination of a video size and frame rate.|
| [OH_AVErrCode OH_AVCapability_GetVideoSupportedPixelFormats(OH_AVCapability *capability, const int32_t **pixelFormats, uint32_t *pixelFormatNum)](#oh_avcapability_getvideosupportedpixelformats) | Obtains the video pixel formats supported by a video codec.|
| [OH_AVErrCode OH_AVCapability_GetVideoSupportedNativeBufferFormats(OH_AVCapability *capability, const OH_NativeBuffer_Format **nativeBufferFormats, uint32_t *nativeBufferFormatNum)](#oh_avcapability_getvideosupportednativebufferformats) | Obtains the OH_NativeBuffer formats supported by a video codec. This function provides the OH_NativeBuffer formats that can be processed by a video codec. For details, see OH_NativeBuffer_Format.|
| [OH_AVErrCode OH_AVCapability_GetSupportedProfiles(OH_AVCapability *capability, const int32_t **profiles, uint32_t *profileNum)](#oh_avcapability_getsupportedprofiles) | Obtains the profiles supported by a codec.|
| [OH_AVErrCode OH_AVCapability_GetSupportedLevelsForProfile(OH_AVCapability *capability, int32_t profile, const int32_t **levels, uint32_t *levelNum)](#oh_avcapability_getsupportedlevelsforprofile) | Obtains the codec levels supported by a profile.|
| [bool OH_AVCapability_AreProfileAndLevelSupported(OH_AVCapability *capability, int32_t profile, int32_t level)](#oh_avcapability_areprofileandlevelsupported) | Checks whether a codec supports the combination of a profile and level.|
| [bool OH_AVCapability_IsFeatureSupported(OH_AVCapability *capability, OH_AVCapabilityFeature feature)](#oh_avcapability_isfeaturesupported) | Checks whether a codec supports a feature.|
| [OH_AVFormat *OH_AVCapability_GetFeatureProperties(OH_AVCapability *capability, OH_AVCapabilityFeature feature)](#oh_avcapability_getfeatureproperties) | Obtains the properties of a feature. You must manually release the OH_AVFormat instance in the return value.|

## Enum Description

### OH_AVCodecCategory

```c
enum OH_AVCodecCategory
```

**Description**

Enumerates the codec categories.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

| Value| Description|
| -- | -- |
| HARDWARE = 0 | Hardware codec.|
| SOFTWARE | Software codec.|

### OH_AVCodecType

```c
enum OH_AVCodecType
```

**Description**

Codec type.

**Since**: 24

| Value| Description|
| -- | -- |
| OH_AVCODEC_TYPE_VIDEO_ENCODER = 0 | Video encoder.<br>**Since**: 24|
| OH_AVCODEC_TYPE_VIDEO_DECODER = 1 | Video decoder.<br>**Since**: 24|
| OH_AVCODEC_TYPE_AUDIO_ENCODER = 2 | Audio encoder.<br>**Since**: 24|
| OH_AVCODEC_TYPE_AUDIO_DECODER = 3 | Audio decoder.<br>**Since**: 24|

### OH_AVCapabilityFeature

```c
enum OH_AVCapabilityFeature
```

**Description**

Enumerates the optional features that can be used in specific codec scenarios.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12

| Value| Description|
| -- | -- |
| VIDEO_ENCODER_TEMPORAL_SCALABILITY = 0 | Temporal scalability feature, which is available only in video encoding scenarios.|
| VIDEO_ENCODER_LONG_TERM_REFERENCE = 1 | Long-term reference frame feature, which is available only in video encoding scenarios.|
| VIDEO_LOW_LATENCY = 2 | Low latency feature, which is available only in video decoding scenarios.|
| VIDEO_ENCODER_B_FRAME = 7 | B-frame encoding feature, which is available only in video encoding scenarios.<br>**Since**: 20|
| VIDEO_DECODER_OUTPUT_IN_DECODING_ORDER = 8 | Decoding-order frame output feature, which is available only in video decoding scenarios.<br>**Since**: 26.0.0|
| VIDEO_ENCODER_PREPROC_DOWNSAMPLING = 9 | Downsampling feature before video encoding, which is available only for video encoders.<br>This capability can be enabled only when the encoder is created through the [OH_VideoEncoder_CreatePrimaryWithPreproc](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_createprimarywithpreproc) or [OH_VideoEncoder_CreateSecondaryFromPrimary](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_createsecondaryfromprimary) API.<br>**Since**: 26.0.0|
| VIDEO_ENCODER_PREPROC_CROP = 10 | Cropping feature before video encoding, which is available only for video encoders.<br>This capability can be enabled only when the encoder is created through the [OH_VideoEncoder_CreatePrimaryWithPreproc](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_createprimarywithpreproc) or [OH_VideoEncoder_CreateSecondaryFromPrimary](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_createsecondaryfromprimary) API.<br>**Since**: 26.0.0|

## Function Description

### OH_AVCodec_GetCapability()

```c
OH_AVCapability *OH_AVCodec_GetCapability(const char *mime, bool isEncoder)
```

**Description**

Obtains the codec capability recommended by the system.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| const char *mime | Pointer to a string that describes the MIME type. For details, see [AVCODEC_MIME_TYPE variables](capi-native-avcodec-base-h.md#variables).|
| bool isEncoder | Whether the instance is an encoder. The value **true** means an encoder and **false** means a decoder.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) * | Pointer to the codec capability instance. If no existing codec matches, NULL is returned.|

### OH_AVCodec_GetCapabilityByCategory()

```c
OH_AVCapability *OH_AVCodec_GetCapabilityByCategory(const char *mime, bool isEncoder, OH_AVCodecCategory category)
```

**Description**

Obtains the codec capability by category, which can be a hardware codec or software codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| const char *mime | Pointer to a string that describes the MIME type. For details, see [AVCODEC_MIME_TYPE variables](capi-native-avcodec-base-h.md#variables).|
| bool isEncoder | Whether the instance is an encoder. The value **true** means an encoder and **false** means a decoder.|
| [OH_AVCodecCategory](#oh_avcodeccategory) category | Codec category.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) * | Pointer to the codec capability instance. If no existing codec matches, NULL is returned.|

### OH_AVCodec_GetCapabilityList()

```c
OH_AVCapability **OH_AVCodec_GetCapabilityList(OH_AVCodecType codecType, uint32_t *count)
```

**Description**

Obtains the list of capabilities for the specified codec type. This function retrieves all matching codec capabilities supported by the system based on the provided codec type.

>**NOTE**
> 
>The memory for the codec capability list is globally maintained by the underlying system. Callers do not need to manage its lifecycle and must not manually allocate or free this memory.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodecType](capi-native-avcapability-h.md#oh_avcodectype) codecType | Codec type to be queried.|
| uint32_t *count |  Pointer to a uint32_t variable for storing the number of matched codec capabilities.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVCapability **](capi-avcapability-oh-avcapability.md) | If a match is found, a pointer to an array of OH_AVCapability instances is returned.<br>         If no matching codec is found or an error occurs, **NULL** is returned.|

### OH_AVCapability_IsHardware()

```c
bool OH_AVCapability_IsHardware(OH_AVCapability *capability)
```

**Description**

Checks whether a codec capability instance describes a hardware codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the codec capability.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Check result for whether the codec capability instance describes a hardware codec. **true** if it describes a hardware codec, **false** otherwise.|

### OH_AVCapability_IsSecure()

```c
bool OH_AVCapability_IsSecure(OH_AVCapability *capability)
```

**Description**

Checks whether the capability instance describes a DRM decoder.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the codec capability.|

**Returns**

| Type| Description|
| -- | -- |
| bool | If the capability instance describes a DRM decoder, **true** is returned.<br>         If the capability instance does not describe a DRM decoder, **false** is returned.|

### OH_AVCapability_GetName()

```c
const char *OH_AVCapability_GetName(OH_AVCapability *capability)
```

**Description**

Obtains the corresponding codec name.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the codec capability.|

**Returns**

| Type| Description|
| -- | -- |
| const char * | Codec name string.|

### OH_AVCapability_GetMimeType()

```c
const char *OH_AVCapability_GetMimeType(OH_AVCapability *capability)
```

**Description**

Obtains the MIME type of the codec.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the codec capability.|

**Returns**

| Type| Description|
| -- | -- |
| const char * | String indicating the MIME type of the codec.|

### OH_AVCapability_CheckMimeType()

```c
bool OH_AVCapability_CheckMimeType(OH_AVCapability *capability, const char *mimeType)
```

**Description**

Checks whether the MIME type of the codec matches the specified MIME type.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the codec capability.|
| const char *mimeType | Target MIME type string to be checked.|

**Returns**

| Type| Description|
| -- | -- |
| bool | If the MIME types match, **true** is returned. Otherwise, **false** is returned.|

### OH_AVCapability_GetMaxSupportedInstances()

```c
int32_t OH_AVCapability_GetMaxSupportedInstances(OH_AVCapability *capability)
```

**Description**

Obtains the maximum number of codec instances supported by a codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the codec capability.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Maximum number of codec instances supported.|

### OH_AVCapability_GetEncoderBitrateRange()

```c
OH_AVErrCode OH_AVCapability_GetEncoderBitrateRange(OH_AVCapability *capability, OH_AVRange *bitrateRange)
```

**Description**

Obtains the bit rate range supported by an encoder.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the encoder capability. If a pointer to the decoder capability is provided, undefined behavior occurs.|
| [OH_AVRange](capi-avcapability-oh-avrange.md) *bitrateRange |  Pointer to the bit rate range supported.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br> **AV_ERR_INVALID_VAL**: The capability instance is invalid or the pointer to the bit rate range is null.|

### OH_AVCapability_IsEncoderBitrateModeSupported()

```c
bool OH_AVCapability_IsEncoderBitrateModeSupported(OH_AVCapability *capability, OH_BitrateMode bitrateMode)
```

**Description**

Checks whether an encoder supports a specific bit rate mode.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the encoder capability. If a pointer to the decoder capability is provided, undefined behavior occurs.|
| [OH_BitrateMode](capi-native-avcodec-base-h.md#oh_bitratemode) bitrateMode | Bit rate mode.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Check result for the support of the bit rate mode. **true** if supported, **false** otherwise.|

### OH_AVCapability_GetEncoderQualityRange()

```c
OH_AVErrCode OH_AVCapability_GetEncoderQualityRange(OH_AVCapability *capability, OH_AVRange *qualityRange)
```

**Description**

Obtains the quality range supported by an encoder.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the encoder capability. If a pointer to the decoder capability is provided, undefined behavior occurs.|
| [OH_AVRange](capi-avcapability-oh-avrange.md) *qualityRange |  Pointer to the quality range supported.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br> **AV_ERR_INVALID_VAL**: The capability instance is invalid or the pointer to the quality range is null.|

### OH_AVCapability_GetEncoderComplexityRange()

```c
OH_AVErrCode OH_AVCapability_GetEncoderComplexityRange(OH_AVCapability *capability, OH_AVRange *complexityRange)
```

**Description**

Obtains the complexity range supported by an encoder.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the encoder capability. If a pointer to the decoder capability is provided, undefined behavior occurs.|
| [OH_AVRange](capi-avcapability-oh-avrange.md) *complexityRange |  Pointer to the complexity range supported.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br> **AV_ERR_INVALID_VAL**: The capability instance is invalid or the pointer to the complexity range is null.|

### OH_AVCapability_GetAudioSupportedSampleRates()

```c
OH_AVErrCode OH_AVCapability_GetAudioSupportedSampleRates(OH_AVCapability *capability, const int32_t **sampleRates, uint32_t *sampleRateNum)
```

**Description**

Obtains the sample rates supported by an audio codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the audio codec capability. If a pointer to the video codec capability is provided, undefined behavior occurs.|
| const int32_t **sampleRates |  Double pointer to the sample rate array.|
| uint32_t *sampleRateNum |  Pointer to the number of elements in the array.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br> **AV_ERR_INVALID_VAL**: The capability instance is invalid, the pointer to the sample rate array is null, or the pointer to the number of elements in the array is null.<br> **AV_ERR_UNKNOWN**: An unknown error occurs.<br> **AV_ERR_NO_MEMORY**: Internal memory allocation failed.|

### OH_AVCapability_GetAudioSupportedSampleRateRanges()

```c
OH_AVErrCode OH_AVCapability_GetAudioSupportedSampleRateRanges(OH_AVCapability *capability, OH_AVRange **sampleRateRanges, uint32_t *rangesNum)
```

**Description**

Obtains the sample rate ranges supported by an audio codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the audio codec capability. If a pointer to the video codec capability is provided, undefined behavior occurs.|
| [OH_AVRange](capi-avcapability-oh-avrange.md) **sampleRateRanges |  Double pointer to the sample rate range array.|
| uint32_t *rangesNum |  Pointer to the number of elements in the array.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br> **AV_ERR_INVALID_VAL**: The capability instance is invalid, the pointer to the sample rate range array is null, or the pointer to the number of elements in the array is null.<br> **AV_ERR_UNKNOWN**: An unknown error occurs.<br> **AV_ERR_NO_MEMORY**: Internal memory allocation failed.|

### OH_AVCapability_GetAudioChannelCountRange()

```c
OH_AVErrCode OH_AVCapability_GetAudioChannelCountRange(OH_AVCapability *capability, OH_AVRange *channelCountRange)
```

**Description**

Obtains the count range of audio channels supported by an audio codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the audio codec capability. If a pointer to the video codec capability is provided, undefined behavior occurs.|
| [OH_AVRange](capi-avcapability-oh-avrange.md) *channelCountRange |  Pointer to the count range of audio channels supported.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br> **AV_ERR_INVALID_VAL**: The capability instance is invalid or the pointer to the count range of audio channels is null.|

### OH_AVCapability_GetVideoWidthAlignment()

```c
OH_AVErrCode OH_AVCapability_GetVideoWidthAlignment(OH_AVCapability *capability, int32_t *widthAlignment)
```

**Description**

Obtains the video width alignment supported by a video codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the video codec capability. If a pointer to the audio codec capability is provided, undefined behavior occurs.|
| int32_t *widthAlignment |  Pointer to the video width alignment supported.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br> **AV_ERR_INVALID_VAL**: The capability instance is invalid or the pointer to the video width alignment is null.|

### OH_AVCapability_GetVideoHeightAlignment()

```c
OH_AVErrCode OH_AVCapability_GetVideoHeightAlignment(OH_AVCapability *capability, int32_t *heightAlignment)
```

**Description**

Obtains the video height alignment supported by a video codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the video codec capability. If a pointer to the audio codec capability is provided, undefined behavior occurs.|
| int32_t *heightAlignment |  Pointer to the video height alignment supported.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br> **AV_ERR_INVALID_VAL**: The capability instance is invalid or the pointer to the video height alignment is null.|

### OH_AVCapability_GetVideoWidthRangeForHeight()

```c
OH_AVErrCode OH_AVCapability_GetVideoWidthRangeForHeight(OH_AVCapability *capability, int32_t height, OH_AVRange *widthRange)
```

**Description**

Obtains the video width range supported by a video codec based on a given height.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the video codec capability. If a pointer to the audio codec capability is provided, undefined behavior occurs.|
| int32_t height | Number of vertical video pixels.|
| [OH_AVRange](capi-avcapability-oh-avrange.md) *widthRange |  Pointer to the video width range supported.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br> **AV_ERR_INVALID_VAL**: The capability instance is invalid, the height is not within the supported height range obtained through [OH_AVCapability_GetVideoHeightRange](#oh_avcapability_getvideoheightrange), or the pointer to the width range is null.|

### OH_AVCapability_GetVideoHeightRangeForWidth()

```c
OH_AVErrCode OH_AVCapability_GetVideoHeightRangeForWidth(OH_AVCapability *capability, int32_t width, OH_AVRange *heightRange)
```

**Description**

Obtains the video height range supported by a video codec based on a given width.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the video codec capability. If a pointer to the audio codec capability is provided, undefined behavior occurs.|
| int32_t width | Number of horizontal video pixels.|
| [OH_AVRange](capi-avcapability-oh-avrange.md) *heightRange |  Pointer to the video height range supported.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br> **AV_ERR_INVALID_VAL**: The capability instance is invalid, the width is not within the supported width range obtained through [OH_AVCapability_GetVideoWidthRange](#oh_avcapability_getvideowidthrange), or the pointer to the height range is null.|

### OH_AVCapability_GetVideoWidthRange()

```c
OH_AVErrCode OH_AVCapability_GetVideoWidthRange(OH_AVCapability *capability, OH_AVRange *widthRange)
```

**Description**

Obtains the video width range supported by a video codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the video codec capability. If a pointer to the audio codec capability is provided, undefined behavior occurs.|
| [OH_AVRange](capi-avcapability-oh-avrange.md) *widthRange |  Pointer to the video width range supported.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br> **AV_ERR_INVALID_VAL**: The capability instance is invalid or the pointer to the video width range is null.|

### OH_AVCapability_GetVideoHeightRange()

```c
OH_AVErrCode OH_AVCapability_GetVideoHeightRange(OH_AVCapability *capability, OH_AVRange *heightRange)
```

**Description**

Obtains the video height range supported by a video codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the video codec capability. If a pointer to the audio codec capability is provided, undefined behavior occurs.|
| [OH_AVRange](capi-avcapability-oh-avrange.md) *heightRange |  Pointer to the video height range supported.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br> **AV_ERR_INVALID_VAL**: The capability instance is invalid or the pointer to the video height range is null.|

### OH_AVCapability_IsVideoSizeSupported()

```c
bool OH_AVCapability_IsVideoSizeSupported(OH_AVCapability *capability, int32_t width, int32_t height)
```

**Description**

Checks whether a video codec supports a specific video size.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the video codec capability. If a pointer to the audio codec capability is provided, undefined behavior occurs.|
| int32_t width | Number of horizontal video pixels.|
| int32_t height | Number of vertical video pixels.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Check result for the support of the video size. **true** if supported, **false** otherwise.|

### OH_AVCapability_GetVideoFrameRateRange()

```c
OH_AVErrCode OH_AVCapability_GetVideoFrameRateRange(OH_AVCapability *capability, OH_AVRange *frameRateRange)
```

**Description**

Obtains the video frame rate range supported by a video codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the video codec capability. If a pointer to the audio codec capability is provided, undefined behavior occurs.|
| [OH_AVRange](capi-avcapability-oh-avrange.md) *frameRateRange |  Pointer to the video frame rate range supported.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br> **AV_ERR_INVALID_VAL**: The capability instance is invalid or the pointer to the video frame rate range is null.|

### OH_AVCapability_GetVideoFrameRateRangeForSize()

```c
OH_AVErrCode OH_AVCapability_GetVideoFrameRateRangeForSize(OH_AVCapability *capability, int32_t width, int32_t height, OH_AVRange *frameRateRange)
```

**Description**

Obtains the video frame rate range supported by a video codec based on a given video size.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the video codec capability. If a pointer to the audio codec capability is provided, undefined behavior occurs.|
| int32_t width | Number of horizontal video pixels.|
| int32_t height | Number of vertical video pixels.|
| [OH_AVRange](capi-avcapability-oh-avrange.md) *frameRateRange |  Pointer to the video frame rate range supported.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br> **AV_ERR_INVALID_VAL**: The capability instance is invalid, the combination of the width and height is not supported, or the pointer to the frame rate range is null.|

### OH_AVCapability_AreVideoSizeAndFrameRateSupported()

```c
bool OH_AVCapability_AreVideoSizeAndFrameRateSupported(OH_AVCapability *capability, int32_t width, int32_t height, int32_t frameRate)
```

**Description**

Checks whether a video codec supports the combination of a video size and frame rate.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the video codec capability. If a pointer to the audio codec capability is provided, undefined behavior occurs.|
| int32_t width | Number of horizontal video pixels.|
| int32_t height | Number of vertical video pixels.|
| int32_t frameRate | Number of frames per second.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Check result for the support of the combination of the video size and frame rate. **true** if supported, **false** otherwise.|

### OH_AVCapability_GetVideoSupportedPixelFormats()

```c
OH_AVErrCode OH_AVCapability_GetVideoSupportedPixelFormats(OH_AVCapability *capability, const int32_t **pixelFormats, uint32_t *pixelFormatNum)
```

**Description**

Obtains the video pixel formats supported by a video codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the video codec capability. If a pointer to the audio codec capability is provided, undefined behavior occurs.|
| const int32_t **pixelFormats | Output Parameter. Pointer to an array of video pixel formats. For details, see [OH_AVPixelFormat](../../reference/apis-avcodec-kit/capi-native-avformat-h.md#oh_avpixelformat). |
| uint32_t *pixelFormatNum |  Pointer to the number of elements in the array.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br> **AV_ERR_INVALID_VAL**: The capability instance is invalid, the pointer to the video pixel format array is null, or the pointer to the number of elements in the array is null.<br> **AV_ERR_UNKNOWN**: An unknown error occurs.<br> **AV_ERR_NO_MEMORY**: Internal memory allocation failed.|

### OH_AVCapability_GetVideoSupportedNativeBufferFormats()

```c
OH_AVErrCode OH_AVCapability_GetVideoSupportedNativeBufferFormats(OH_AVCapability *capability, const OH_NativeBuffer_Format **nativeBufferFormats, uint32_t *nativeBufferFormatNum)
```

**Description**

Obtains the OH_NativeBuffer formats supported by a video codec. This function provides the OH_NativeBuffer formats that can be processed by a video codec. For details, see OH_NativeBuffer_Format.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the video codec capability.|
| const [OH_NativeBuffer_Format](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_format) **nativeBufferFormats |  Double pointer to the OH_NativeBuffer_Format array.|
| uint32_t *nativeBufferFormatNum |  Pointer to the number of elements in the array.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_INVALID_VAL**: The capability instance is invalid, the capability instance is an audio codec capability, the pointer to the OH_NativeBuffer_Format array is nullptr,<br> or the pointer to the number of elements in the array is nullptr.<br>         **AV_ERR_UNKNOWN**: An unknown error occurs.<br>         **AV_ERR_NO_MEMORY**: Internal memory allocation failed.|

### OH_AVCapability_GetSupportedProfiles()

```c
OH_AVErrCode OH_AVCapability_GetSupportedProfiles(OH_AVCapability *capability, const int32_t **profiles, uint32_t *profileNum)
```

**Description**

Obtains the profiles supported by a codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the codec capability.|
| const int32_t **profiles | Output Parameter. Pointer to the profile array. For example, for H.264 profiles, see [OH_AVCProfile](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#oh_avcprofile). |
| uint32_t *profileNum |  Pointer to the number of profiles in the array.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br> **AV_ERR_INVALID_VAL**: The capability instance is invalid, the pointer to the profile array is null, or the pointer to the number of elements in the array is null.<br> **AV_ERR_UNKNOWN**: An unknown error occurs.<br> **AV_ERR_NO_MEMORY**: Internal memory allocation failed.|

### OH_AVCapability_GetSupportedLevelsForProfile()

```c
OH_AVErrCode OH_AVCapability_GetSupportedLevelsForProfile(OH_AVCapability *capability, int32_t profile, const int32_t **levels, uint32_t *levelNum)
```

**Description**

Obtains the codec levels supported by a profile.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the codec capability.|
| int32_t profile | Codec profile.|
| const int32_t **levels | Output Parameter. Pointer to the level array. For example, for H.264 levels, see [OH_AVCLevel](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#oh_avclevel). |
| uint32_t *levelNum |  Pointer to the number of elements in the array.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br> **AV_ERR_INVALID_VAL**: The capability instance is invalid, the level is not in the supported level array obtained through [OH_AVCapability_GetSupportedProfiles](#oh_avcapability_getsupportedprofiles), the pointer to the level array is null, or the pointer to the number of elements in the array is null.<br> **AV_ERR_UNKNOWN**: An unknown error occurs.<br> **AV_ERR_NO_MEMORY**: Internal memory allocation failed.|

### OH_AVCapability_AreProfileAndLevelSupported()

```c
bool OH_AVCapability_AreProfileAndLevelSupported(OH_AVCapability *capability, int32_t profile, int32_t level)
```

**Description**

Checks whether a codec supports the combination of a profile and level.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the codec capability.|
| int32_t profile | Codec profile.|
| int32_t level | Level of the codec.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Check result for the support of the combination of the profile and level. **true** if supported, **false** otherwise.|

### OH_AVCapability_IsFeatureSupported()

```c
bool OH_AVCapability_IsFeatureSupported(OH_AVCapability *capability, OH_AVCapabilityFeature feature)
```

**Description**

Checks whether a codec supports a feature.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the codec capability.|
| [OH_AVCapabilityFeature](#oh_avcapabilityfeature) feature | Codec feature.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Check result for the feature. **true** if supported, **false** otherwise.|

### OH_AVCapability_GetFeatureProperties()

```c
OH_AVFormat *OH_AVCapability_GetFeatureProperties(OH_AVCapability *capability, OH_AVCapabilityFeature feature)
```

**Description**

Obtains the properties of a feature. You must manually release the OH_AVFormat instance in the return value.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | Pointer to the codec capability.|
| [OH_AVCapabilityFeature](#oh_avcapabilityfeature) feature | Codec feature.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVFormat](capi-core-oh-avformat.md) * | Pointer to an OH_AVFormat instance.|