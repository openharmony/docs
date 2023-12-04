# AVCapability


## Overview

The **AVCapability** module provides functions for querying the codec capability.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Since**

10


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [native_avcapability.h](native__avcapability_8h.md) | Declares the native APIs used to query the codec capability.<br>**File to include**: <multimedia/player_framework/native_avcapability.h><br>**Library**: libnative_media_codecbase.so| 


### Structs

| Name| Description| 
| -------- | -------- |
| [OH_AVRange](_o_h___a_v_range.md) | Defines the value range, which contains the minimum value and maximum value.| 


### Types

| Name| Description| 
| -------- | -------- |
| [OH_BitrateMode](#oh_bitratemode) | Defines an enum that enumerates the bit rate modes of an encoder.| 
| [OH_AVRange](#oh_avrange) | Defines a struct for the value range, which contains the minimum value and maximum value.| 
| [OH_AVCodecCategory](#oh_avcodeccategory) | Defines an enum that enumerates the codec categories.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_BitrateMode](#oh_bitratemode) { **BITRATE_MODE_CBR** = 0, **BITRATE_MODE_VBR** = 1, **BITRATE_MODE_CQ** = 2 } | Enumerates the bit rate modes of an encoder.| 
| [OH_AVCodecCategory](#oh_avcodeccategory) { **HARDWARE** = 0, **SOFTWARE** } | Enumerates the codec categories.| 


### Functions

| Name| Description| 
| -------- | -------- |
| \*[OH_AVCodec_GetCapability](#oh_avcodec_getcapability) (const char \*mime, bool isEncoder) | Obtains the codec capability recommended by the system.| 
| \*[OH_AVCodec_GetCapabilityByCategory](#oh_avcodec_getcapabilitybycategory) (const char \*mime, bool isEncoder, [OH_AVCodecCategory](#oh_avcodeccategory) category) | Obtains the codec capability by category, which can be a hardware codec or software codec.| 
| [OH_AVCapability_IsHardware](#oh_avcapability_ishardware) (OH_AVCapability \*capability) | Checks whether a codec capability instance describes a hardware codec.| 
| \*[OH_AVCapability_GetName](#oh_avcapability_getname) (OH_AVCapability \*capability) | Obtains the codec name.| 
| [OH_AVCapability_GetMaxSupportedInstances](#oh_avcapability_getmaxsupportedinstances) (OH_AVCapability \*capability) | Obtains the maximum number of codec instances supported by a codec.| 
| [OH_AVCapability_GetEncoderBitrateRange](#oh_avcapability_getencoderbitraterange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*bitrateRange) | Obtains the bit rate range supported by an encoder.| 
| [OH_AVCapability_IsEncoderBitrateModeSupported](#oh_avcapability_isencoderbitratemodesupported) (OH_AVCapability \*capability, [OH_BitrateMode](#oh_bitratemode) bitrateMode) | Checks whether an encoder supports a specific bit rate mode.| 
| [OH_AVCapability_GetEncoderQualityRange](#oh_avcapability_getencoderqualityrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*qualityRange) | Obtains the quality range supported by an encoder.| 
| [OH_AVCapability_GetEncoderComplexityRange](#oh_avcapability_getencodercomplexityrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*complexityRange) | Obtains the complexity range supported by an encoder.| 
| [OH_AVCapability_GetAudioSupportedSampleRates](#oh_avcapability_getaudiosupportedsamplerates) (OH_AVCapability \*capability, const int32_t \*\*sampleRates, uint32_t \*sampleRateNum) | Obtains the sampling rates supported by an audio codec.| 
| [OH_AVCapability_GetAudioChannelCountRange](#oh_avcapability_getaudiochannelcountrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*channelCountRange) | Obtains the count range of audio channels supported by an audio codec.| 
| [OH_AVCapability_GetVideoWidthAlignment](#oh_avcapability_getvideowidthalignment) (OH_AVCapability \*capability, int32_t \*widthAlignment) | Obtains the video width alignment supported by a video codec.| 
| [OH_AVCapability_GetVideoHeightAlignment](#oh_avcapability_getvideoheightalignment) (OH_AVCapability \*capability, int32_t \*heightAlignment) | Obtains the video height alignment supported by a video codec.| 
| [OH_AVCapability_GetVideoWidthRangeForHeight](#oh_avcapability_getvideowidthrangeforheight) (OH_AVCapability \*capability, int32_t height, [OH_AVRange](_o_h___a_v_range.md) \*widthRange) | Obtains the video width range supported by a video codec based on a given height.| 
| [OH_AVCapability_GetVideoHeightRangeForWidth](#oh_avcapability_getvideoheightrangeforwidth) (OH_AVCapability \*capability, int32_t width, [OH_AVRange](_o_h___a_v_range.md) \*heightRange) | Obtains the video height range supported by a video codec based on a given width.| 
| [OH_AVCapability_GetVideoWidthRange](#oh_avcapability_getvideowidthrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*widthRange) | Obtains the video width range supported by a video codec.| 
| [OH_AVCapability_GetVideoHeightRange](#oh_avcapability_getvideoheightrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*heightRange) | Obtains the video height range supported by a video codec.| 
| [OH_AVCapability_IsVideoSizeSupported](#oh_avcapability_isvideosizesupported) (OH_AVCapability \*capability, int32_t width, int32_t height) | Checks whether a video codec supports a specific video size.| 
| [OH_AVCapability_GetVideoFrameRateRange](#oh_avcapability_getvideoframeraterange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*frameRateRange) | Obtains the video frame rate range supported by a video codec.| 
| [OH_AVCapability_GetVideoFrameRateRangeForSize](#oh_avcapability_getvideoframeraterangeforsize) (OH_AVCapability \*capability, int32_t width, int32_t height, [OH_AVRange](_o_h___a_v_range.md) \*frameRateRange) | Obtains the video frame rate range supported by a video codec based on a given video size.| 
| [OH_AVCapability_AreVideoSizeAndFrameRateSupported](#oh_avcapability_arevideosizeandframeratesupported) (OH_AVCapability \*capability, int32_t width, int32_t height, int32_t frameRate) | Checks whether a video codec supports the combination of a video size and frame rate.| 
| [OH_AVCapability_GetVideoSupportedPixelFormats](#oh_avcapability_getvideosupportedpixelformats) (OH_AVCapability \*capability, const int32_t \*\*pixelFormats, uint32_t \*pixelFormatNum) | Obtains the video pixel formats supported by a video codec.| 
| [OH_AVCapability_GetSupportedProfiles](#oh_avcapability_getsupportedprofiles) (OH_AVCapability \*capability, const int32_t \*\*profiles, uint32_t \*profileNum) | Obtains the profiles supported by a codec.| 
| [OH_AVCapability_GetSupportedLevelsForProfile](#oh_avcapability_getsupportedlevelsforprofile) (OH_AVCapability \*capability, int32_t profile, const int32_t \*\*levels, uint32_t \*levelNum) | Obtains the codec levels supported by a profile.| 
| [OH_AVCapability_AreProfileAndLevelSupported](#oh_avcapability_areprofileandlevelsupported) (OH_AVCapability \*capability, int32_t profile, int32_t level) | Checks whether a codec supports the combination of a profile and level.| 


### Variables

| Name| Description| 
| -------- | -------- |
| **OH_AVRange::minVal** | Defines the minimum value.| 
| **OH_AVRange::maxVal** | Defines the maximum value.| 


## Type Description


### OH_AVCodecCategory

  
```
typedef enum OH_AVCodecCategory OH_AVCodecCategory
```

**Description**

Defines an enum that enumerates the codec categories.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Since**

10


### OH_AVRange

  
```
typedef struct OH_AVRange OH_AVRange
```

**Description**

Defines a struct for the value range, which contains the minimum value and maximum value.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Since**

10


### OH_BitrateMode

  
```
typedef enum OH_BitrateMode OH_BitrateMode
```

**Description**

Defines an enum that enumerates the bit rate modes of an encoder.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Since**

10


## Enum Description


### OH_AVCodecCategory

  
```
enum OH_AVCodecCategory
```

**Description**

Defines an enum that enumerates the codec categories.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Since**

10

| Value| Description|
| -------- | -------- |
| HARDWARE | Hardware codec.| 
| SOFTWARE | Software codec.| 


### OH_BitrateMode

  
```
enum OH_BitrateMode
```

**Description**

Defines an enum that enumerates the bit rate modes of an encoder.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Since**

10

| Value| Description|
| -------- | -------- |
| BITRATE_MODE_CBR | Constant bit rate.| 
| BITRATE_MODE_VBR | Variable bit rate.| 
| BITRATE_MODE_CQ | Constant quality.| 


## Function Description


### OH_AVCapability_AreProfileAndLevelSupported()

  
```
bool OH_AVCapability_AreProfileAndLevelSupported (OH_AVCapability *capability, int32_t profile, int32_t level)
```

**Description**

Checks whether a codec supports the combination of a profile and level.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the codec capability.| 
| profile | Profile of the codec.| 
| level | Level of the codec.| 

**Returns**

Returns **true** if the combination of the profile and level is supported; returns **false** otherwise.

**Since**

10


### OH_AVCapability_AreVideoSizeAndFrameRateSupported()

  
```
bool OH_AVCapability_AreVideoSizeAndFrameRateSupported (OH_AVCapability *capability, int32_t width, int32_t height, int32_t frameRate)
```

**Description**

Checks whether a video codec supports the combination of a video size and frame rate.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the video codec capability. A pointer to the audio codec capability cannot be filled in.| 
| width | Number of horizontal video pixels.| 
| height | Number of vertical video pixels.| 
| frameRate | Number of frames per second.| 

**Returns**

Returns **true** if the combination of the video size and frame rate is supported; returns **false** otherwise.

**Since**

10


### OH_AVCapability_GetAudioChannelCountRange()

  
```
OH_AVErrCode OH_AVCapability_GetAudioChannelCountRange (OH_AVCapability *capability, OH_AVRange *channelCountRange)
```

**Description**

Obtains the count range of audio channels supported by an audio codec.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the audio codec capability. A pointer to the video codec capability cannot be filled in.| 
| channelCountRange | Output parameter. Pointer to the count range of audio channels supported.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

10


### OH_AVCapability_GetAudioSupportedSampleRates()

  
```
OH_AVErrCode OH_AVCapability_GetAudioSupportedSampleRates (OH_AVCapability *capability, const int32_t **sampleRates, uint32_t *sampleRateNum)
```

**Description**

Obtains the sampling rates supported by an audio codec.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the audio codec capability. A pointer to the video codec capability cannot be filled in.| 
| sampleRates | Output parameter. Double pointer to the sampling rate array.| 
| sampleRateNum | Output parameter. Pointer to the number of elements in the array.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

10


### OH_AVCapability_GetEncoderBitrateRange()

  
```
OH_AVErrCode OH_AVCapability_GetEncoderBitrateRange (OH_AVCapability *capability, OH_AVRange *bitrateRange)
```

**Description**

Obtains the bit rate range supported by an encoder.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the encoder capability. A pointer to the decoder capability cannot be filled in.| 
| bitrateRange | Output parameter. Pointer to the bit rate range supported.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

10


### OH_AVCapability_GetEncoderComplexityRange()

  
```
OH_AVErrCode OH_AVCapability_GetEncoderComplexityRange (OH_AVCapability *capability, OH_AVRange *complexityRange)
```

**Description**

Obtains the complexity range supported by an encoder.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the encoder capability. A pointer to the decoder capability cannot be filled in.| 
| complexityRange | Output parameter. Pointer to the complexity range supported.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

10


### OH_AVCapability_GetEncoderQualityRange()

  
```
OH_AVErrCode OH_AVCapability_GetEncoderQualityRange (OH_AVCapability *capability, OH_AVRange *qualityRange)
```

**Description**

Obtains the quality range supported by an encoder.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the encoder capability. A pointer to the decoder capability cannot be filled in.| 
| qualityRange | Output parameter. Pointer to the quality range supported.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

10


### OH_AVCapability_GetMaxSupportedInstances()

  
```
int32_t OH_AVCapability_GetMaxSupportedInstances (OH_AVCapability *capability)
```

**Description**

Obtains the maximum number of codec instances supported by a codec.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the codec capability.| 

**Returns**

Returns the maximum number of codec instances supported.

**Since**

10


### OH_AVCapability_GetName()

  
```
const char* OH_AVCapability_GetName (OH_AVCapability *capability)
```

**Description**

Obtains the codec name.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the codec capability.| 

**Returns**

Returns the codec name string.

**Since**

10


### OH_AVCapability_GetSupportedLevelsForProfile()

  
```
OH_AVErrCode OH_AVCapability_GetSupportedLevelsForProfile (OH_AVCapability *capability, int32_t profile, const int32_t **levels, uint32_t *levelNum)
```

**Description**

Obtains the codec levels supported by a profile.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the codec capability.| 
| profile | Profile of the codec.| 
| levels | Output parameter. Double pointer to the codec level array.| 
| levelNum | Output parameter. Pointer to the number of elements in the array.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

10


### OH_AVCapability_GetSupportedProfiles()

  
```
OH_AVErrCode OH_AVCapability_GetSupportedProfiles (OH_AVCapability *capability, const int32_t **profiles, uint32_t *profileNum)
```

**Description**

Obtains the profiles supported by a codec.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the codec capability.| 
| profiles | Output parameter. Double pointer to the profile array.| 
| profileNum | Output parameter. Pointer to the number of elements in the array.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

10


### OH_AVCapability_GetVideoFrameRateRange()

  
```
OH_AVErrCode OH_AVCapability_GetVideoFrameRateRange (OH_AVCapability *capability, OH_AVRange *frameRateRange)
```

**Description**

Obtains the video frame rate range supported by a video codec.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the video codec capability. A pointer to the audio codec capability cannot be filled in.| 
| frameRateRange | Output parameter. Pointer to the video frame rate range supported.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

10


### OH_AVCapability_GetVideoFrameRateRangeForSize()

  
```
OH_AVErrCode OH_AVCapability_GetVideoFrameRateRangeForSize (OH_AVCapability *capability, int32_t width, int32_t height, OH_AVRange *frameRateRange)
```

**Description**

Obtains the video frame rate range supported by a video codec based on a given video size.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the video codec capability. A pointer to the audio codec capability cannot be filled in.| 
| width | Number of horizontal video pixels.| 
| height | Number of vertical video pixels.| 
| frameRateRange | Output parameter. Pointer to the video frame rate range supported.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

10


### OH_AVCapability_GetVideoHeightAlignment()

  
```
OH_AVErrCode OH_AVCapability_GetVideoHeightAlignment (OH_AVCapability *capability, int32_t *heightAlignment)
```

**Description**

Obtains the video height alignment supported by a video codec.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the video codec capability. A pointer to the audio codec capability cannot be filled in.| 
| heightAlignment | Output parameter. Pointer to the video height alignment supported.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

10


### OH_AVCapability_GetVideoHeightRange()

  
```
OH_AVErrCode OH_AVCapability_GetVideoHeightRange (OH_AVCapability *capability, OH_AVRange *heightRange)
```

**Description**

Obtains the video height range supported by a video codec.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the video codec capability. A pointer to the audio codec capability cannot be filled in.| 
| heightRange | Output parameter. Pointer to the video height range supported.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

10


### OH_AVCapability_GetVideoHeightRangeForWidth()

  
```
OH_AVErrCode OH_AVCapability_GetVideoHeightRangeForWidth (OH_AVCapability *capability, int32_t width, OH_AVRange *heightRange)
```

**Description**

Obtains the video height range supported by a video codec based on a given width.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the video codec capability. A pointer to the audio codec capability cannot be filled in.| 
| width | Number of horizontal video pixels.| 
| heightRange | Output parameter. Pointer to the video height range supported.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

10


### OH_AVCapability_GetVideoSupportedPixelFormats()

  
```
OH_AVErrCode OH_AVCapability_GetVideoSupportedPixelFormats (OH_AVCapability *capability, const int32_t **pixelFormats, uint32_t *pixelFormatNum)
```

**Description**

Obtains the video pixel formats supported by a video codec.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the video codec capability. A pointer to the audio codec capability cannot be filled in.| 
| pixelFormats | Output parameter. Double pointer to the video pixel format array.| 
| pixelFormatNum | Output parameter. Pointer to the number of elements in the array.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

10


### OH_AVCapability_GetVideoWidthAlignment()

  
```
OH_AVErrCode OH_AVCapability_GetVideoWidthAlignment (OH_AVCapability *capability, int32_t *widthAlignment)
```

**Description**

Obtains the video width alignment supported by a video codec.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the video codec capability. A pointer to the audio codec capability cannot be filled in.| 
| widthAlignment | Output parameter. Pointer to the video width alignment supported.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

10


### OH_AVCapability_GetVideoWidthRange()

  
```
OH_AVErrCode OH_AVCapability_GetVideoWidthRange (OH_AVCapability *capability, OH_AVRange *widthRange)
```

**Description**

Obtains the video width range supported by a video codec.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the video codec capability. A pointer to the audio codec capability cannot be filled in.| 
| widthRange | Output parameter. Pointer to the video width range supported.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

10


### OH_AVCapability_GetVideoWidthRangeForHeight()

  
```
OH_AVErrCode OH_AVCapability_GetVideoWidthRangeForHeight (OH_AVCapability *capability, int32_t height, OH_AVRange *widthRange)
```

**Description**

Obtains the video width range supported by a video codec based on a given height.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the video codec capability. A pointer to the audio codec capability cannot be filled in.| 
| height | Number of vertical video pixels.| 
| widthRange | Output parameter. Pointer to the video width range supported.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

10


### OH_AVCapability_IsEncoderBitrateModeSupported()

  
```
bool OH_AVCapability_IsEncoderBitrateModeSupported (OH_AVCapability *capability, OH_BitrateMode bitrateMode)
```

**Description**

Checks whether an encoder supports a specific bit rate mode.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the encoder capability. A pointer to the decoder capability cannot be filled in.| 
| bitrateMode | Bit rate mode.| 

**Returns**

Returns **true** if the bit rate mode is supported; returns **false** otherwise.

**Since**

10


### OH_AVCapability_IsHardware()

  
```
bool OH_AVCapability_IsHardware (OH_AVCapability *capability)
```

**Description**

Checks whether a codec capability instance describes a hardware codec.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the codec capability.| 

**Returns**

Returns **true** if the codec capability instance describes a hardware codec; returns **false**.

**Since**

10


### OH_AVCapability_IsVideoSizeSupported()

  
```
bool OH_AVCapability_IsVideoSizeSupported (OH_AVCapability *capability, int32_t width, int32_t height)
```

**Description**

Checks whether a video codec supports a specific video size.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| capability | Pointer to the video codec capability. A pointer to the audio codec capability cannot be filled in.| 
| width | Number of horizontal video pixels.| 
| height | Number of vertical video pixels.| 

**Returns**

Returns **true** if the video size is supported; returns **false** otherwise.

**Since**

10


### OH_AVCodec_GetCapability()

  
```
OH_AVCapability* OH_AVCodec_GetCapability (const char *mime, bool isEncoder)
```

**Description**

Obtains the codec capability recommended by the system.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| mime | Pointer to a string that describes the MIME type. For details, see [AVCODEC_MIMETYPE](_codec_base.md#variables).| 
| isEncoder | Whether the instance is an encoder. The value **true** means an encoder and **false** means a decoder.| 

**Returns**

Returns a pointer to the codec capability instance if an existing codec matches; returns NULL otherwise.

**Since**

10


### OH_AVCodec_GetCapabilityByCategory()

  
```
OH_AVCapability* OH_AVCodec_GetCapabilityByCategory (const char *mime, bool isEncoder, OH_AVCodecCategory category)
```

**Description**

Obtains the codec capability by category,

which can be a hardware codec or software codec.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| mime | Pointer to a string that describes the MIME type. For details, see [AVCODEC_MIMETYPE](_codec_base.md#variables).| 
| isEncoder | Whether the instance is an encoder. The value **true** means an encoder and **false** means a decoder.| 
| category | Codec category.| 

**Returns**

Returns a pointer to the codec capability instance if an existing codec matches; returns NULL otherwise.

**Since**

10
