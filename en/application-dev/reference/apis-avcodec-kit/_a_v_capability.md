# AVCapability


## Overview

The AVCapability module provides the functions for querying the codec capability.

For details about the development guide and sample, see [Obtaining Supported Codecs](../../media/avcodec/obtain-supported-codecs.md).

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [native_avcapability.h](native__avcapability_8h.md) | Declares the native APIs used to query the codec capability.| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [OH_AVRange](_o_h___a_v_range.md) | Describes the value range, which contains the minimum value and maximum value. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_AVRange](_o_h___a_v_range.md) [OH_AVRange](#oh_avrange) | Defines a struct for the value range, which contains the minimum value and maximum value. | 
| typedef enum [OH_AVCodecCategory](#oh_avcodeccategory-1) [OH_AVCodecCategory](#oh_avcodeccategory) | Defines an enum for the codec categories. | 
| typedef enum [OH_AVCapabilityFeature](#oh_avcapabilityfeature-1) [OH_AVCapabilityFeature](#oh_avcapabilityfeature) | Defines an enum for the optional features that can be used in specific codec scenarios. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_AVCodecCategory](#oh_avcodeccategory-1) { HARDWARE = 0, SOFTWARE } | Enumerates the codec categories. | 
| [OH_AVCapabilityFeature](#oh_avcapabilityfeature-1) {<br> VIDEO_ENCODER_TEMPORAL_SCALABILITY = 0, <br>VIDEO_ENCODER_LONG_TERM_REFERENCE = 1, <br>VIDEO_LOW_LATENCY = 2 <br>} | Enumerates the optional features that can be used in specific codec scenarios. | 


### Functions

| Name| Description| 
| -------- | -------- |
| OH_AVCapability \*[OH_AVCodec_GetCapability](#oh_avcodec_getcapability) (const char \*mime, bool isEncoder) | Obtains the codec capability recommended by the system. | 
| OH_AVCapability \*[OH_AVCodec_GetCapabilityByCategory](#oh_avcodec_getcapabilitybycategory) (const char \*mime, bool isEncoder, [OH_AVCodecCategory](#oh_avcodeccategory) category) | Obtains the codec capability by category,| 
| bool [OH_AVCapability_IsHardware](#oh_avcapability_ishardware) (OH_AVCapability \*capability) | Checks whether a codec capability instance describes a hardware codec. | 
| const char \* [OH_AVCapability_GetName](#oh_avcapability_getname) (OH_AVCapability \*capability) | Obtains the codec name. | 
| int32_t [OH_AVCapability_GetMaxSupportedInstances](#oh_avcapability_getmaxsupportedinstances) (OH_AVCapability \*capability) | Obtains the maximum number of codec instances supported by a codec. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetEncoderBitrateRange](#oh_avcapability_getencoderbitraterange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*bitrateRange) | Obtains the bit rate range supported by an encoder. | 
| bool [OH_AVCapability_IsEncoderBitrateModeSupported](#oh_avcapability_isencoderbitratemodesupported) (OH_AVCapability \*capability, [OH_BitrateMode](_codec_base.md#oh_bitratemode) bitrateMode) | Checks whether an encoder supports a specific bit rate mode. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetEncoderQualityRange](#oh_avcapability_getencoderqualityrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*qualityRange) | Obtains the quality range supported by an encoder. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetEncoderComplexityRange](#oh_avcapability_getencodercomplexityrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*complexityRange) | Obtains the complexity range supported by an encoder. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetAudioSupportedSampleRates](#oh_avcapability_getaudiosupportedsamplerates) (OH_AVCapability \*capability, const int32_t \*\*sampleRates, uint32_t \*sampleRateNum) | Obtains the sample rates supported by an audio codec. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetAudioChannelCountRange](#oh_avcapability_getaudiochannelcountrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*channelCountRange) | Obtains the count range of audio channels supported by an audio codec. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetVideoWidthAlignment](#oh_avcapability_getvideowidthalignment) (OH_AVCapability \*capability, int32_t \*widthAlignment) | Obtains the video width alignment supported by a video codec. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetVideoHeightAlignment](#oh_avcapability_getvideoheightalignment) (OH_AVCapability \*capability, int32_t \*heightAlignment) | Obtains the video height alignment supported by a video codec. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetVideoWidthRangeForHeight](#oh_avcapability_getvideowidthrangeforheight) (OH_AVCapability \*capability, int32_t height, [OH_AVRange](_o_h___a_v_range.md) \*widthRange) | Obtains the video width range supported by a video codec based on a given height. | 
| OH_AVErrCode [OH_AVCapability_GetVideoHeightRangeForWidth](#oh_avcapability_getvideoheightrangeforwidth) (OH_AVCapability \*capability, int32_t width, [OH_AVRange](_o_h___a_v_range.md) \*heightRange) | Obtains the video height range supported by a video codec based on a given width. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetVideoWidthRange](#oh_avcapability_getvideowidthrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*widthRange) | Obtains the video width range supported by a video codec. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetVideoHeightRange](#oh_avcapability_getvideoheightrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*heightRange) | Obtains the video height range supported by a video codec. | 
| bool [OH_AVCapability_IsVideoSizeSupported](#oh_avcapability_isvideosizesupported) (OH_AVCapability \*capability, int32_t width, int32_t height) | Checks whether a video codec supports a specific video size. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetVideoFrameRateRange](#oh_avcapability_getvideoframeraterange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*frameRateRange) | Obtains the video frame rate range supported by a video codec. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetVideoFrameRateRangeForSize](#oh_avcapability_getvideoframeraterangeforsize) (OH_AVCapability \*capability, int32_t width, int32_t height, [OH_AVRange](_o_h___a_v_range.md) \*frameRateRange) | Obtains the video frame rate range supported by a video codec based on a given video size. | 
| bool [OH_AVCapability_AreVideoSizeAndFrameRateSupported](#oh_avcapability_arevideosizeandframeratesupported) (OH_AVCapability \*capability, int32_t width, int32_t height, int32_t frameRate) | Checks whether a video codec supports the combination of a video size and frame rate. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetVideoSupportedPixelFormats](#oh_avcapability_getvideosupportedpixelformats) (OH_AVCapability \*capability, const int32_t \*\*pixelFormats, uint32_t \*pixelFormatNum) | Obtains the video pixel formats supported by a video codec. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetSupportedProfiles](#oh_avcapability_getsupportedprofiles) (OH_AVCapability \*capability, const int32_t \*\*profiles, uint32_t \*profileNum) | Obtains the profiles supported by a codec. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetSupportedLevelsForProfile](#oh_avcapability_getsupportedlevelsforprofile) (OH_AVCapability \*capability, int32_t profile, const int32_t \*\*levels, uint32_t \*levelNum) | Obtains the codec levels supported by a profile. | 
| bool [OH_AVCapability_AreProfileAndLevelSupported](#oh_avcapability_areprofileandlevelsupported) (OH_AVCapability \*capability, int32_t profile, int32_t level) | Checks whether a codec supports the combination of a profile and level. | 
| bool [OH_AVCapability_IsFeatureSupported](#oh_avcapability_isfeaturesupported) (OH_AVCapability \*capability, [OH_AVCapabilityFeature](#oh_avcapabilityfeature) feature) | Checks whether a codec supports a feature. | 
| OH_AVFormat \* [OH_AVCapability_GetFeatureProperties](#oh_avcapability_getfeatureproperties) (OH_AVCapability \*capability, [OH_AVCapabilityFeature](#oh_avcapabilityfeature) feature) | Obtains the properties of a feature. The caller must manually release the **OH_AVFormat** instance in the return value. | 


## Type Description


### OH_AVCapabilityFeature

```
typedef enum OH_AVCapabilityFeature OH_AVCapabilityFeature
```
**Description**

Defines an enum for the optional features that can be used in specific codec scenarios.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_AVCodecCategory

```
typedef enum OH_AVCodecCategory OH_AVCodecCategory
```
**Description**

Defines an enum for the codec categories.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_AVRange

```
typedef struct OH_AVRange OH_AVRange
```
**Description**

Defines a struct for the value range, which contains the minimum value and maximum value.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

## Enum Description


### OH_AVCapabilityFeature

```
enum OH_AVCapabilityFeature
```
**Description**

Enumerates the optional features that can be used in specific codec scenarios.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12

| Value| Description| 
| -------- | -------- |
| VIDEO_ENCODER_TEMPORAL_SCALABILITY  | Temporal scalability feature, which is available only in video encoding scenarios.  | 
| VIDEO_ENCODER_LONG_TERM_REFERENCE  | Long-term reference frame feature, which is available only in video encoding scenarios.  | 
| VIDEO_LOW_LATENCY  | Low latency feature, which is available only in video encoding and decoding scenarios.  | 


### OH_AVCodecCategory

```
enum OH_AVCodecCategory
```
**Description**

Enumerates the codec categories.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

| Value| Description| 
| -------- | -------- |
| HARDWARE  | Hardware codec.  | 
| SOFTWARE  | Software codec.  | 


## Function Description


### OH_AVCapability_AreProfileAndLevelSupported()

```
bool OH_AVCapability_AreProfileAndLevelSupported (OH_AVCapability *capability, int32_t profile, int32_t level)
```
**Description**

Checks whether a codec supports the combination of a profile and level.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the codec capability. | 
| profile | Codec profile. | 
| level | Level of the codec. | 

**Returns**

Returns **true** if the combination of the profile and level is supported; returns **false** otherwise.


### OH_AVCapability_AreVideoSizeAndFrameRateSupported()

```
bool OH_AVCapability_AreVideoSizeAndFrameRateSupported (OH_AVCapability *capability, int32_t width, int32_t height, int32_t frameRate)
```
**Description**

Checks whether a video codec supports the combination of a video size and frame rate.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the video codec capability. A pointer to the audio codec capability cannot be filled in. | 
| width | Number of horizontal video pixels. | 
| height | Number of vertical video pixels. | 
| frameRate | Number of frames per second. | 

**Returns**

Returns **true** if the combination of the video size and frame rate is supported; returns **false** otherwise.


### OH_AVCapability_GetAudioChannelCountRange()

```
OH_AVErrCode OH_AVCapability_GetAudioChannelCountRange (OH_AVCapability *capability, OH_AVRange *channelCountRange)
```
**Description**

Obtains the count range of audio channels supported by an audio codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the audio codec capability. A pointer to the video codec capability cannot be filled in. | 
| channelCountRange | Output parameter. Pointer to the count range of audio channels supported. | 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**AV_ERR_INVALID_VAL** is returned if the capability instance is invalid or the pointer to the count range of audio channels is null.


### OH_AVCapability_GetAudioSupportedSampleRates()

```
OH_AVErrCode OH_AVCapability_GetAudioSupportedSampleRates (OH_AVCapability *capability, const int32_t **sampleRates, uint32_t *sampleRateNum)
```
**Description**

Obtains the sample rates supported by an audio codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the audio codec capability. A pointer to the video codec capability cannot be filled in. | 
| sampleRates | Output parameter. Double pointer to the sample rate array. | 
| sampleRateNum | Output parameter. Pointer to the number of elements in the array. | 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**AV_ERR_INVALID_VAL** is returned if the capability instance is invalid, the pointer to the sample rate array is null, or the pointer to the number of elements in the array is null. **AV_ERR_UNKNOWN** is returned in the case of an unknown error. **AV_ERR_NO_MEMORY** is returned if internal memory allocation fails.


### OH_AVCapability_GetEncoderBitrateRange()

```
OH_AVErrCode OH_AVCapability_GetEncoderBitrateRange (OH_AVCapability *capability, OH_AVRange *bitrateRange)
```
**Description**

Obtains the bit rate range supported by an encoder.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the encoder capability. A pointer to the decoder capability cannot be filled in. | 
| bitrateRange | Output parameter. Pointer to the bit rate range supported. | 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**AV_ERR_INVALID_VAL** is returned if the capability instance is invalid or the pointer to the bit rate range is null.


### OH_AVCapability_GetEncoderComplexityRange()

```
OH_AVErrCode OH_AVCapability_GetEncoderComplexityRange (OH_AVCapability *capability, OH_AVRange *complexityRange)
```
**Description**

Obtains the complexity range supported by an encoder.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the encoder capability. A pointer to the decoder capability cannot be filled in. | 
| complexityRange | Output parameter. Pointer to the complexity range supported. | 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**AV_ERR_INVALID_VAL** is returned if the capability instance is invalid or the pointer to the complexity range is null.


### OH_AVCapability_GetEncoderQualityRange()

```
OH_AVErrCode OH_AVCapability_GetEncoderQualityRange (OH_AVCapability *capability, OH_AVRange *qualityRange)
```
**Description**

Obtains the quality range supported by an encoder.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the encoder capability. A pointer to the decoder capability cannot be filled in. | 
| qualityRange | Output parameter. Pointer to the quality range supported. | 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**AV_ERR_INVALID_VAL** is returned if the capability instance is invalid or the pointer to the quality range is null.


### OH_AVCapability_GetFeatureProperties()

```
OH_AVFormat* OH_AVCapability_GetFeatureProperties (OH_AVCapability *capability, OH_AVCapabilityFeature feature)
```
**Description**

Obtains the properties of a feature. The caller must manually release the **OH_AVFormat** instance in the return value.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the codec capability. | 
| feature | Codec feature. For details about the available options, see [OH_AVCapabilityFeature](#oh_avcapabilityfeature). | 

**Returns**

Returns the pointer to an **OH_AVFormat** instance.


### OH_AVCapability_GetMaxSupportedInstances()

```
int32_t OH_AVCapability_GetMaxSupportedInstances (OH_AVCapability *capability)
```
**Description**

Obtains the maximum number of codec instances supported by a codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the codec capability. | 

**Returns**

Returns the maximum number of codec instances supported.


### OH_AVCapability_GetName()

```
const char* OH_AVCapability_GetName (OH_AVCapability *capability)
```
**Description**

Obtains the codec name.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the codec capability. | 

**Returns**

Returns the codec name string.


### OH_AVCapability_GetSupportedLevelsForProfile()

```
OH_AVErrCode OH_AVCapability_GetSupportedLevelsForProfile (OH_AVCapability *capability, int32_t profile, const int32_t **levels, uint32_t *levelNum)
```
**Description**

Obtains the codec levels supported by a profile.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the codec capability. | 
| profile | Codec profile. | 
| levels | Output parameter. Double pointer to the codec level array. | 
| levelNum | Output parameter. Pointer to the number of elements in the array. | 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**AV_ERR_INVALID_VAL** is returned if the capability instance is invalid, the level is not in the supported level array obtained through [OH_AVCapability_GetSupportedProfiles](#oh_avcapability_getsupportedprofiles), the pointer to the level array is null, or the pointer to the number of elements in the array is null. **AV_ERR_UNKNOWN** is returned in the case of an unknown error. **AV_ERR_NO_MEMORY** is returned if internal memory allocation fails.


### OH_AVCapability_GetSupportedProfiles()

```
OH_AVErrCode OH_AVCapability_GetSupportedProfiles (OH_AVCapability *capability, const int32_t **profiles, uint32_t *profileNum)
```
**Description**

Obtains the profiles supported by a codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the codec capability. | 
| profiles | Output parameter. Double pointer to the profile array. | 
| profileNum | Output parameter. Pointer to the number of profiles in the array. | 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**AV_ERR_INVALID_VAL** is returned if the capability instance is invalid, the pointer to the profile array is null, or the pointer to the number of elements in the array is null. **AV_ERR_UNKNOWN** is returned in the case of an unknown error. **AV_ERR_NO_MEMORY** is returned if internal memory allocation fails.


### OH_AVCapability_GetVideoFrameRateRange()

```
OH_AVErrCode OH_AVCapability_GetVideoFrameRateRange (OH_AVCapability *capability, OH_AVRange *frameRateRange)
```
**Description**

Obtains the video frame rate range supported by a video codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the video codec capability. A pointer to the audio codec capability cannot be filled in. | 
| frameRateRange | Output parameter. Pointer to the video frame rate range supported. | 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**AV_ERR_INVALID_VAL** is returned if the capability instance is invalid or the pointer to the video frame rate range is null.


### OH_AVCapability_GetVideoFrameRateRangeForSize()

```
OH_AVErrCode OH_AVCapability_GetVideoFrameRateRangeForSize (OH_AVCapability *capability, int32_t width, int32_t height, OH_AVRange *frameRateRange)
```
**Description**

Obtains the video frame rate range supported by a video codec based on a given video size.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the video codec capability. A pointer to the audio codec capability cannot be filled in. | 
| width | Number of horizontal video pixels. | 
| height | Number of vertical video pixels. | 
| frameRateRange | Output parameter. Pointer to the video frame rate range supported. | 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**AV_ERR_INVALID_VAL** is returned if the capability instance is invalid, the combination of the width and height is not supported, or the pointer to the frame rate range is null.


### OH_AVCapability_GetVideoHeightAlignment()

```
OH_AVErrCode OH_AVCapability_GetVideoHeightAlignment (OH_AVCapability *capability, int32_t *heightAlignment)
```
**Description**

Obtains the video height alignment supported by a video codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the video codec capability. A pointer to the audio codec capability cannot be filled in. | 
| heightAlignment | Output parameter. Pointer to the video height alignment supported. | 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**AV_ERR_INVALID_VAL** is returned if the capability instance is invalid or the pointer to the video height alignment is null.


### OH_AVCapability_GetVideoHeightRange()

```
OH_AVErrCode OH_AVCapability_GetVideoHeightRange (OH_AVCapability *capability, OH_AVRange *heightRange)
```
**Description**

Obtains the video height range supported by a video codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the video codec capability. A pointer to the audio codec capability cannot be filled in. | 
| heightRange | Output parameter. Pointer to the video height range supported. | 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**AV_ERR_INVALID_VAL** is returned if the capability instance is invalid or the pointer to the video height range is null.


### OH_AVCapability_GetVideoHeightRangeForWidth()

```
OH_AVErrCode OH_AVCapability_GetVideoHeightRangeForWidth (OH_AVCapability *capability, int32_t width, OH_AVRange *heightRange)
```
**Description**

Obtains the video height range supported by a video codec based on a given width.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the video codec capability. A pointer to the audio codec capability cannot be filled in. | 
| width | Number of horizontal video pixels. | 
| heightRange | Output parameter. Pointer to the video height range supported. | 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**AV_ERR_INVALID_VAL** is returned if the capability instance is invalid, the width is not within the supported width range obtained through [OH_AVCapability_GetVideoWidthRange](#oh_avcapability_getvideowidthrange), or the pointer to the height range is null.


### OH_AVCapability_GetVideoSupportedPixelFormats()

```
OH_AVErrCode OH_AVCapability_GetVideoSupportedPixelFormats (OH_AVCapability *capability, const int32_t **pixelFormats, uint32_t *pixelFormatNum)
```
**Description**

Obtains the video pixel formats supported by a video codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the video codec capability. A pointer to the audio codec capability cannot be filled in. | 
| pixelFormats | Output parameter. Double pointer to the video pixel format array. | 
| pixelFormatNum | Output parameter. Pointer to the number of elements in the array. | 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**AV_ERR_INVALID_VAL** is returned if the capability instance is invalid, the pointer to the video pixel format array is null, or the pointer to the number of elements in the array is null. **AV_ERR_UNKNOWN** is returned in the case of an unknown error. **AV_ERR_NO_MEMORY** is returned if internal memory allocation fails.


### OH_AVCapability_GetVideoWidthAlignment()

```
OH_AVErrCode OH_AVCapability_GetVideoWidthAlignment (OH_AVCapability *capability, int32_t *widthAlignment)
```
**Description**

Obtains the video width alignment supported by a video codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the video codec capability. A pointer to the audio codec capability cannot be filled in. | 
| widthAlignment | Output parameter. Pointer to the video width alignment supported. | 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**AV_ERR_INVALID_VAL** is returned if the capability instance is invalid or the pointer to the video width alignment is null.


### OH_AVCapability_GetVideoWidthRange()

```
OH_AVErrCode OH_AVCapability_GetVideoWidthRange (OH_AVCapability *capability, OH_AVRange *widthRange)
```
**Description**

Obtains the video width range supported by a video codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the video codec capability. A pointer to the audio codec capability cannot be filled in. | 
| widthRange | Output parameter. Pointer to the video width range supported. | 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**AV_ERR_INVALID_VAL** is returned if the capability instance is invalid or the pointer to the video width range is null.


### OH_AVCapability_GetVideoWidthRangeForHeight()

```
OH_AVErrCode OH_AVCapability_GetVideoWidthRangeForHeight (OH_AVCapability *capability, int32_t height, OH_AVRange *widthRange)
```
**Description**

Obtains the video width range supported by a video codec based on a given height.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the video codec capability. A pointer to the audio codec capability cannot be filled in. | 
| height | Number of vertical video pixels. | 
| widthRange | Output parameter. Pointer to the video width range supported. | 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**AV_ERR_INVALID_VAL** is returned if the capability instance is invalid, the height is not within the supported height range obtained through [OH_AVCapability_GetVideoHeightRange](#oh_avcapability_getvideoheightrange), or the pointer to the width range is null.


### OH_AVCapability_IsEncoderBitrateModeSupported()

```
bool OH_AVCapability_IsEncoderBitrateModeSupported (OH_AVCapability *capability, OH_BitrateMode bitrateMode)
```
**Description**

Checks whether an encoder supports a specific bit rate mode.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the encoder capability. A pointer to the decoder capability cannot be filled in. | 
| bitrateMode | Bit rate mode. | 

**Returns**

Returns **true** if the bit rate mode is supported; returns **false** otherwise.


### OH_AVCapability_IsFeatureSupported()

```
bool OH_AVCapability_IsFeatureSupported (OH_AVCapability *capability, OH_AVCapabilityFeature feature)
```
**Description**

Checks whether a codec supports a feature.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the codec capability. | 
| feature | Codec feature. For details about the available options, see [OH_AVCapabilityFeature](#oh_avcapabilityfeature). | 

**Returns**

Returns **true** if the feature is supported; returns **false** otherwise.


### OH_AVCapability_IsHardware()

```
bool OH_AVCapability_IsHardware (OH_AVCapability *capability)
```
**Description**

Checks whether a codec capability instance describes a hardware codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the codec capability. | 

**Returns**

Returns **true** if the codec capability instance describes a hardware codec; returns **false**.


### OH_AVCapability_IsVideoSizeSupported()

```
bool OH_AVCapability_IsVideoSizeSupported (OH_AVCapability *capability, int32_t width, int32_t height)
```
**Description**

Checks whether a video codec supports a specific video size.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the video codec capability. A pointer to the audio codec capability cannot be filled in. | 
| width | Number of horizontal video pixels. | 
| height | Number of vertical video pixels. | 

**Returns**

Returns **true** if the video size is supported; returns **false** otherwise.


### OH_AVCodec_GetCapability()

```
OH_AVCapability* OH_AVCodec_GetCapability (const char *mime, bool isEncoder)
```
**Description**

Obtains the codec capability recommended by the system.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| mime | Pointer to a string that describes the MIME type. For details, see **AVCODEC_MIME_TYPE**. | 
| isEncoder | Whether the instance is an encoder. The value **true** means an encoder and **false** means a decoder. | 

**Returns**

Returns a pointer to the codec capability instance if an existing codec matches; returns NULL otherwise.


### OH_AVCodec_GetCapabilityByCategory()

```
OH_AVCapability* OH_AVCodec_GetCapabilityByCategory (const char *mime, bool isEncoder, OH_AVCodecCategory category)
```
**Description**

Obtains the codec capability by category, which can be a hardware codec or software codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| mime | Pointer to a string that describes the MIME type. For details, see [AVCODEC_MIMETYPE](_codec_base.md#variables). | 
| isEncoder | Whether the instance is an encoder. The value **true** means an encoder and **false** means a decoder. | 
| category | Codec category. | 

**Returns**

Returns a pointer to the codec capability instance if an existing codec matches; returns NULL otherwise.
