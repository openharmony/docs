# native_avcapability.h


## Overview

The **native_avcapability.h** file declares the native APIs used to query the codec capability.

**Library**: libnative_media_codecbase.so

**Since**: 10

**Related module**: [AVCapability](_a_v_capability.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[OH_AVRange](_o_h___a_v_range.md) | Describes the value range, which contains the minimum value and maximum value. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [OH_BitrateMode](_a_v_capability.md#oh_bitratemode-1) [OH_BitrateMode](_a_v_capability.md#oh_bitratemode) | Defines an enum for bit rate modes of an encoder. | 
| typedef struct [OH_AVRange](_o_h___a_v_range.md) [OH_AVRange](_a_v_capability.md#oh_avrange) | Defines the value range, which contains the minimum value and maximum value. | 
| typedef enum [OH_AVCodecCategory](_a_v_capability.md#oh_avcodeccategory-1) [OH_AVCodecCategory](_a_v_capability.md#oh_avcodeccategory) | Defines an enum for codec categories. | 
| typedef enum [OH_AVCapabilityFeature](_a_v_capability.md#oh_avcapabilityfeature-1) [OH_AVCapabilityFeature](_a_v_capability.md#oh_avcapabilityfeature) | Defines an enum for optional features that can be used in specific codec scenarios. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_BitrateMode](_a_v_capability.md#oh_bitratemode-1) { <br>BITRATE_MODE_CBR = 0, <br>BITRATE_MODE_VBR = 1, <br>BITRATE_MODE_CQ = 2 } | Enumerates the bit rate modes of an encoder. | 
| [OH_AVCodecCategory](_a_v_capability.md#oh_avcodeccategory-1) { HARDWARE = 0, SOFTWARE } | Enumerates the codec categories. | 
| [OH_AVCapabilityFeature](_a_v_capability.md#oh_avcapabilityfeature-1) {<br> VIDEO_ENCODER_TEMPORAL_SCALABILITY = 0, <br>VIDEO_ENCODER_LONG_TERM_REFERENCE = 1, <br>VIDEO_LOW_LATENCY = 2 <br>} | Enumerates the optional features that can be used in specific codec scenarios. | 


### Functions

| Name| Description| 
| -------- | -------- |
| OH_AVCapability \*[OH_AVCodec_GetCapability](_a_v_capability.md#oh_avcodec_getcapability) (const char \*mime, bool isEncoder) | Obtains the codec capability recommended by the system. | 
| OH_AVCapability \*[OH_AVCodec_GetCapabilityByCategory](_a_v_capability.md#oh_avcodec_getcapabilitybycategory) (const char \*mime, bool isEncoder, [OH_AVCodecCategory](_a_v_capability.md#oh_avcodeccategory) category) | Obtains the codec capability by category, which can be a hardware codec or software codec. | 
| bool [OH_AVCapability_IsHardware](_a_v_capability.md#oh_avcapability_ishardware) (OH_AVCapability \*capability) | Checks whether a codec capability instance describes a hardware codec. | 
| const char \*[OH_AVCapability_GetName](_a_v_capability.md#oh_avcapability_getname) (OH_AVCapability \*capability) | Obtains the codec name. | 
| int32_t [OH_AVCapability_GetMaxSupportedInstances](_a_v_capability.md#oh_avcapability_getmaxsupportedinstances) (OH_AVCapability \*capability) | Obtains the maximum number of codec instances supported by a codec. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetEncoderBitrateRange](_a_v_capability.md#oh_avcapability_getencoderbitraterange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*bitrateRange) | Obtains the bit rate range supported by an encoder. | 
| bool [OH_AVCapability_IsEncoderBitrateModeSupported](_a_v_capability.md#oh_avcapability_isencoderbitratemodesupported) (OH_AVCapability \*capability, [OH_BitrateMode](_a_v_capability.md#oh_bitratemode) bitrateMode) | Checks whether an encoder supports a specific bit rate mode. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetEncoderQualityRange](_a_v_capability.md#oh_avcapability_getencoderqualityrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*qualityRange) | Obtains the quality range supported by an encoder. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetEncoderComplexityRange](_a_v_capability.md#oh_avcapability_getencodercomplexityrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*complexityRange) | Obtains the complexity range supported by an encoder. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetAudioSupportedSampleRates](_a_v_capability.md#oh_avcapability_getaudiosupportedsamplerates) (OH_AVCapability \*capability, const int32_t \*\*sampleRates, uint32_t \*sampleRateNum) | Obtains the sample rates supported by an audio codec. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetAudioChannelCountRange](_a_v_capability.md#oh_avcapability_getaudiochannelcountrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*channelCountRange) | Obtains the count range of audio channels supported by an audio codec. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetVideoWidthAlignment](_a_v_capability.md#oh_avcapability_getvideowidthalignment) (OH_AVCapability \*capability, int32_t \*widthAlignment) | Obtains the video width alignment supported by a video codec. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetVideoHeightAlignment](_a_v_capability.md#oh_avcapability_getvideoheightalignment) (OH_AVCapability \*capability, int32_t \*heightAlignment) | Obtains the video height alignment supported by a video codec. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetVideoWidthRangeForHeight](_a_v_capability.md#oh_avcapability_getvideowidthrangeforheight) (OH_AVCapability \*capability, int32_t height, [OH_AVRange](_o_h___a_v_range.md) \*widthRange) | Obtains the video width range supported by a video codec based on a given height. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetVideoHeightRangeForWidth](_a_v_capability.md#oh_avcapability_getvideoheightrangeforwidth) (OH_AVCapability \*capability, int32_t width, [OH_AVRange](_o_h___a_v_range.md) \*heightRange) | Obtains the video height range supported by a video codec based on a given width. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetVideoWidthRange](_a_v_capability.md#oh_avcapability_getvideowidthrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*widthRange) | Obtains the video width range supported by a video codec. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetVideoHeightRange](_a_v_capability.md#oh_avcapability_getvideoheightrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*heightRange) | Obtains the video height range supported by a video codec. | 
| bool [OH_AVCapability_IsVideoSizeSupported](_a_v_capability.md#oh_avcapability_isvideosizesupported) (OH_AVCapability \*capability, int32_t width, int32_t height) | Checks whether a video codec supports a specific video size. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetVideoFrameRateRange](_a_v_capability.md#oh_avcapability_getvideoframeraterange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*frameRateRange) | Obtains the video frame rate range supported by a video codec. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetVideoFrameRateRangeForSize](_a_v_capability.md#oh_avcapability_getvideoframeraterangeforsize) (OH_AVCapability \*capability, int32_t width, int32_t height, [OH_AVRange](_o_h___a_v_range.md) \*frameRateRange) | Obtains the video frame rate range supported by a video codec based on a given video size. | 
| bool [OH_AVCapability_AreVideoSizeAndFrameRateSupported](_a_v_capability.md#oh_avcapability_arevideosizeandframeratesupported) (OH_AVCapability \*capability, int32_t width, int32_t height, int32_t frameRate) | Checks whether a video codec supports the combination of a video size and frame rate. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetVideoSupportedPixelFormats](_a_v_capability.md#oh_avcapability_getvideosupportedpixelformats) (OH_AVCapability \*capability, const int32_t \*\*pixelFormats, uint32_t \*pixelFormatNum) | Obtains the video pixel formats supported by a video codec. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetSupportedProfiles](_a_v_capability.md#oh_avcapability_getsupportedprofiles) (OH_AVCapability \*capability, const int32_t \*\*profiles, uint32_t \*profileNum) | Obtains the profiles supported by a codec. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetSupportedLevelsForProfile](_a_v_capability.md#oh_avcapability_getsupportedlevelsforprofile) (OH_AVCapability \*capability, int32_t profile, const int32_t \*\*levels, uint32_t \*levelNum) | Obtains the codec levels supported by a profile. | 
| bool [OH_AVCapability_AreProfileAndLevelSupported](_a_v_capability.md#oh_avcapability_areprofileandlevelsupported) (OH_AVCapability \*capability, int32_t profile, int32_t level) | Checks whether a codec supports the combination of a profile and level. | 
| bool [OH_AVCapability_IsFeatureSupported](_a_v_capability.md#oh_avcapability_isfeaturesupported) (OH_AVCapability \*capability, [OH_AVCapabilityFeature](_a_v_capability.md#oh_avcapabilityfeature) feature) | Checks whether a codec supports a feature. | 
| OH_AVFormat \*[OH_AVCapability_GetFeatureProperties](_a_v_capability.md#oh_avcapability_getfeatureproperties) (OH_AVCapability \*capability, [OH_AVCapabilityFeature](_a_v_capability.md#oh_avcapabilityfeature) feature) | Obtains the properties of a feature. The caller must manually release the **OH_AVFormat** instance in the return value. | 
